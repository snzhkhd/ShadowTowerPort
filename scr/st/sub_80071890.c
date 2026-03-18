#include "recomp.h"
#include "disable_warnings.h"

void sub_80071890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sll         $a0, $a0, 7
    ctx->r4 = S32(ctx->r4) << 7;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // sll         $a2, $a2, 7
    ctx->r6 = S32(ctx->r6) << 7;
    // andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // addu        $a2, $a2, $a3
    ctx->r6 = ADD32(ctx->r6, ctx->r7);
    // subu        $a2, $a2, $a0
    ctx->r6 = SUB32(ctx->r6, ctx->r4);
    // bgez        $a2, L_800718C4
    if (SIGNED(ctx->r6) >= 0) {
        // addu        $a1, $a2, $zero
        ctx->r5 = ADD32(ctx->r6, 0);
        goto L_800718C4;
    }
    // addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // negu        $a1, $a2
    ctx->r5 = SUB32(0, ctx->r6);
L_800718C4:
    // lui         $v0, 0x2AAA
    ctx->r2 = S32(0X2AAA << 16);
    // ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $a1, 31
    ctx->r2 = S32(ctx->r5) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $v1, $t1, 8
    ctx->r3 = S32(ctx->r9) >> 8;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) << 9;
    // bltz        $a2, L_80071904
    if (SIGNED(ctx->r6) < 0) {
        // subu        $v1, $a1, $v0
        ctx->r3 = SUB32(ctx->r5, ctx->r2);
        goto L_80071904;
    }
    // subu        $v1, $a1, $v0
    ctx->r3 = SUB32(ctx->r5, ctx->r2);
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // j           L_8007191C
    // sllv        $v0, $v0, $a0
    ctx->r2 = S32(ctx->r2) << (ctx->r4 & 31);
    goto L_8007191C;
    // sllv        $v0, $v0, $a0
    ctx->r2 = S32(ctx->r2) << (ctx->r4 & 31);
L_80071904:
    // beq         $v1, $zero, L_80071914
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0x600
        ctx->r2 = ADD32(0, 0X600);
        goto L_80071914;
    }
    // addiu       $v0, $zero, 0x600
    ctx->r2 = ADD32(0, 0X600);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
L_80071914:
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // srav        $v0, $v0, $a0
    ctx->r2 = S32(ctx->r2) >> (ctx->r4 & 31);
L_8007191C:
    // andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    // addiu       $a0, $zero, 0x103B
    ctx->r4 = ADD32(0, 0X103B);
    // mult        $a2, $a0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $a3, $a2, 12
    ctx->r7 = S32(ctx->r6) << 12;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // bgez        $v1, L_8007193C
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8007193C;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8007193C:
    // srl         $v1, $v0, 5
    ctx->r3 = S32(U32(ctx->r2) >> 5);
    // andi        $t0, $v0, 0x1F
    ctx->r8 = ctx->r2 & 0X1F;
    // mflo        $t1
    ctx->r9 = lo;
    // beq         $v1, $zero, L_8007198C
    if (ctx->r3 == 0) {
        // sw          $t1, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r9;
        goto L_8007198C;
    }
    // sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // mult        $a2, $a0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
L_80071954:
    // sll         $v0, $a0, 6
    ctx->r2 = S32(ctx->r4) << 6;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // mflo        $a3
    ctx->r7 = lo;
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // srl         $a0, $a0, 12
    ctx->r4 = S32(U32(ctx->r4) >> 12);
    // mult        $a2, $a0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slt         $v0, $a1, $v1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // mflo        $t1
    ctx->r9 = lo;
    // bne         $v0, $zero, L_80071954
    if (ctx->r2 != 0) {
        // sw          $t1, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r9;
        goto L_80071954;
    }
    // sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
L_8007198C:
    // lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(0X0, ctx->r29);
    // nop

    // subu        $v0, $t1, $a3
    ctx->r2 = SUB32(ctx->r9, ctx->r7);
    // srl         $v0, $v0, 5
    ctx->r2 = S32(U32(ctx->r2) >> 5);
    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // addu        $v0, $a3, $t1
    ctx->r2 = ADD32(ctx->r7, ctx->r9);
    // srl         $v1, $v0, 12
    ctx->r3 = S32(U32(ctx->r2) >> 12);
    // sltiu       $v0, $v1, 0x4000
    ctx->r2 = ctx->r3 < 0X4000 ? 1 : 0;
    // bne         $v0, $zero, L_800719C0
    if (ctx->r2 != 0) {
        // andi        $v0, $v1, 0xFFFF
        ctx->r2 = ctx->r3 & 0XFFFF;
        goto L_800719C0;
    }
    // andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // addiu       $v1, $zero, 0x3FFF
    ctx->r3 = ADD32(0, 0X3FFF);
    // andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
L_800719C0:
    // jr          $ra
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
