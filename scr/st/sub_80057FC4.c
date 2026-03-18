#include "recomp.h"
#include "disable_warnings.h"

void sub_80057FC4(uint8_t* rdram, recomp_context* ctx) {
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
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, -0x2E40
    ctx->r4 = ADD32(ctx->r4, -0X2E40);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(0X0, ctx->r20);
    // lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(0X10, ctx->r4);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // lw          $v0, 0x4($s4)
    ctx->r2 = MEM_W(0X4, ctx->r20);
    // lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(0X14, ctx->r4);
    // mflo        $a2
    ctx->r6 = lo;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(0X18, ctx->r4);
    // lw          $v0, 0x8($s4)
    ctx->r2 = MEM_W(0X8, ctx->r20);
    // mflo        $a1
    ctx->r5 = lo;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // andi        $s2, $s3, 0x8000
    ctx->r18 = ctx->r19 & 0X8000;
    // andi        $s3, $s3, 0xFFF
    ctx->r19 = ctx->r19 & 0XFFF;
    // lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(0X40, ctx->r29);
    // addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
    // mflo        $v1
    ctx->r3 = lo;
    // jal         0x800746C4
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    SquareRoot0(rdram, ctx);
    goto after_0;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    after_0:
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // slt         $s0, $v0, $s0
    ctx->r16 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // beq         $s0, $zero, L_800580B8
    if (ctx->r16 == 0) {
        // subu        $v0, $s1, $v0
        ctx->r2 = SUB32(ctx->r17, ctx->r2);
        goto L_800580B8;
    }
    // subu        $v0, $s1, $v0
    ctx->r2 = SUB32(ctx->r17, ctx->r2);
    // mult        $v0, $s5
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // div         $zero, $v0, $s1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r17)));
    // bne         $s1, $zero, L_80058090
    if (ctx->r17 != 0) {
        // nop
    
        goto L_80058090;
    }
    // nop

    // break       7
    do_break(2147844236);
L_80058090:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s1, $at, L_800580A8
    if (ctx->r17 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_800580A8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_800580A8
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_800580A8;
    }
    // nop

    // break       6
    do_break(2147844260);
L_800580A8:
    // mflo        $s1
    ctx->r17 = lo;
    // nop

    // bgtz        $s1, L_800580C0
    if (SIGNED(ctx->r17) > 0) {
        // slti        $v0, $s1, 0x80
        ctx->r2 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
        goto L_800580C0;
    }
    // slti        $v0, $s1, 0x80
    ctx->r2 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
L_800580B8:
    // j           L_800581F8
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_800581F8;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800580C0:
    // bne         $v0, $zero, L_800580CC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800580CC;
    }
    // nop

    // addiu       $s1, $zero, 0x7F
    ctx->r17 = ADD32(0, 0X7F);
L_800580CC:
    // bne         $s2, $zero, L_800580F4
    if (ctx->r18 != 0) {
        // addiu       $a0, $s1, 0x20
        ctx->r4 = ADD32(ctx->r17, 0X20);
        goto L_800580F4;
    }
    // addiu       $a0, $s1, 0x20
    ctx->r4 = ADD32(ctx->r17, 0X20);
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // bgez        $v0, L_800580E8
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_800580E8;
    }
    // nop

    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
L_800580E8:
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // j           L_80058120
    // addu        $s2, $s1, $v0
    ctx->r18 = ADD32(ctx->r17, ctx->r2);
    goto L_80058120;
    // addu        $s2, $s1, $v0
    ctx->r18 = ADD32(ctx->r17, ctx->r2);
L_800580F4:
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // addu        $s2, $a0, $v0
    ctx->r18 = ADD32(ctx->r4, ctx->r2);
    // slti        $v0, $s2, 0x80
    ctx->r2 = SIGNED(ctx->r18) < 0X80 ? 1 : 0;
    // beq         $v0, $zero, L_8005811C
    if (ctx->r2 == 0) {
        // addiu       $v1, $zero, 0x7F
        ctx->r3 = ADD32(0, 0X7F);
        goto L_8005811C;
    }
    // addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
L_8005811C:
    // addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
L_80058120:
    // lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // addiu       $s0, $s0, -0x2E40
    ctx->r16 = ADD32(ctx->r16, -0X2E40);
    // lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(0X0, ctx->r20);
    // lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(0X10, ctx->r16);
    // lw          $v0, 0x8($s4)
    ctx->r2 = MEM_W(0X8, ctx->r20);
    // lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(0X18, ctx->r16);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x8004A1B4
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    sub_8004A1B4(rdram, ctx);
    goto after_1;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_1:
    // lh          $v1, 0x22($s0)
    ctx->r3 = MEM_HS(0X22, ctx->r16);
    // nop

    // subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
    // bgez        $a0, L_80058160
    if (SIGNED(ctx->r4) >= 0) {
        // slti        $v0, $a0, 0x800
        ctx->r2 = SIGNED(ctx->r4) < 0X800 ? 1 : 0;
        goto L_80058160;
    }
    // slti        $v0, $a0, 0x800
    ctx->r2 = SIGNED(ctx->r4) < 0X800 ? 1 : 0;
    // addiu       $a0, $a0, 0x1000
    ctx->r4 = ADD32(ctx->r4, 0X1000);
    // slti        $v0, $a0, 0x800
    ctx->r2 = SIGNED(ctx->r4) < 0X800 ? 1 : 0;
L_80058160:
    // beq         $v0, $zero, L_800581A4
    if (ctx->r2 == 0) {
        // addu        $s0, $s2, $zero
        ctx->r16 = ADD32(ctx->r18, 0);
        goto L_800581A4;
    }
    // addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
    // jal         0x800743F4
    // nop

    rsin(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // mflo        $v1
    ctx->r3 = lo;
    // subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_80058198
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80058198;
    }
    // nop

    // addiu       $v0, $v0, 0x7F
    ctx->r2 = ADD32(ctx->r2, 0X7F);
L_80058198:
    // sra         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) >> 7;
    // j           L_800581DC
    // subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    goto L_800581DC;
    // subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
L_800581A4:
    // jal         0x800743F4
    // nop

    rsin(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // mflo        $v1
    ctx->r3 = lo;
    // subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_800581D4
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_800581D4;
    }
    // nop

    // addiu       $v0, $v0, 0x7F
    ctx->r2 = ADD32(ctx->r2, 0X7F);
L_800581D4:
    // sra         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) >> 7;
    // addu        $s2, $s0, $v0
    ctx->r18 = ADD32(ctx->r16, ctx->r2);
L_800581DC:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(0X44, ctx->r29);
    // jal         0x80058318
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80058318(rdram, ctx);
    goto after_4;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_4:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
L_800581F8:
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
