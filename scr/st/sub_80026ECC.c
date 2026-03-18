#include "recomp.h"
#include "disable_warnings.h"

void sub_80026ECC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // lui         $v0, 0x1F80
    ctx->r2 = S32(0X1F80 << 16);
    // lbu         $v0, 0x2E5($v0)
    ctx->r2 = MEM_BU(0X2E5, ctx->r2);
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // bne         $v0, $zero, L_80026F08
    if (ctx->r2 != 0) {
        // sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
        goto L_80026F08;
    }
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // addu        $t3, $t5, $zero
    ctx->r11 = ADD32(ctx->r13, 0);
    // addu        $t6, $t3, $zero
    ctx->r14 = ADD32(ctx->r11, 0);
    // addu        $t7, $t3, $zero
    ctx->r15 = ADD32(ctx->r11, 0);
    // addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // addiu       $t0, $zero, 0x15
    ctx->r8 = ADD32(0, 0X15);
    // j           L_80026F24
    // addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    goto L_80026F24;
    // addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
L_80026F08:
    // addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // addiu       $t0, $zero, 0x12
    ctx->r8 = ADD32(0, 0X12);
    // addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // addu        $t3, $t7, $zero
    ctx->r11 = ADD32(ctx->r15, 0);
    // addu        $t5, $t6, $zero
    ctx->r13 = ADD32(ctx->r14, 0);
L_80026F24:
    // andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // beq         $v0, $zero, L_80027084
    if (ctx->r2 == 0) {
        // srl         $a0, $a0, 1
        ctx->r4 = S32(U32(ctx->r4) >> 1);
        goto L_80027084;
    }
    // srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // sll         $a0, $t0, 1
    ctx->r4 = S32(ctx->r8) << 1;
    // div         $zero, $v1, $a0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r4)));
    // bne         $a0, $zero, L_80026F4C
    if (ctx->r4 != 0) {
        // nop
    
        goto L_80026F4C;
    }
    // nop

    // break       7
    do_break(2147643208);
L_80026F4C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a0, $at, L_80026F64
    if (ctx->r4 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80026F64;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_80026F64
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_80026F64;
    }
    // nop

    // break       6
    do_break(2147643232);
L_80026F64:
    // mflo        $a0
    ctx->r4 = lo;
    // mfhi        $v0
    ctx->r2 = hi;
    // andi        $t3, $t4, 0xFFFF
    ctx->r11 = ctx->r12 & 0XFFFF;
    // nop

    // mult        $v0, $t3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // nop

    // nop

    // mult        $t5, $a0
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x304($t2)
    ctx->r3 = MEM_W(0X304, ctx->r10);
    // nop

    // lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(0X8, ctx->r3);
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addiu       $t0, $s0, 0x28
    ctx->r8 = ADD32(ctx->r16, 0X28);
    // sltu        $v0, $v0, $t0
    ctx->r2 = ctx->r2 < ctx->r8 ? 1 : 0;
    // mflo        $a0
    ctx->r4 = lo;
    // bne         $v0, $zero, L_80027318
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80027318;
    }
    // nop

    // sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // lw          $v0, 0x328($t2)
    ctx->r2 = MEM_W(0X328, ctx->r10);
    // addu        $v1, $t4, $t1
    ctx->r3 = ADD32(ctx->r12, ctx->r9);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x328($t2)
    MEM_W(0X328, ctx->r10) = ctx->r2;
    // addu        $v0, $t5, $a0
    ctx->r2 = ADD32(ctx->r13, ctx->r4);
    // sb          $t1, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r9;
    // sb          $a0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r4;
    // sb          $v1, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r3;
    // sb          $a0, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r4;
    // sb          $t1, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r9;
    // sb          $v0, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r2;
    // sb          $v1, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r3;
    // sb          $v0, 0x25($s0)
    MEM_B(0X25, ctx->r16) = ctx->r2;
    // lw          $v0, 0x304($gp)
    ctx->r2 = MEM_W(0X304, ctx->r28);
    // nop

    // beq         $v0, $zero, L_8002707C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8002707C;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lhu         $v1, -0x7E54($v1)
    ctx->r3 = MEM_HU(-0X7E54, ctx->r3);
    // nop

    // bne         $v1, $v0, L_80027028
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $t3, 0x1
        ctx->r2 = ADD32(ctx->r11, 0X1);
        goto L_80027028;
    }
    // addiu       $v0, $t3, 0x1
    ctx->r2 = ADD32(ctx->r11, 0X1);
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lhu         $v1, -0x7E60($v1)
    ctx->r3 = MEM_HU(-0X7E60, ctx->r3);
    // j           L_80027038
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    goto L_80027038;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
L_80027028:
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lhu         $v1, -0x7E5E($v1)
    ctx->r3 = MEM_HU(-0X7E5E, ctx->r3);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
L_80027038:
    // mflo        $t8
    ctx->r24 = lo;
    // subu        $a1, $a1, $t8
    ctx->r5 = SUB32(ctx->r5, ctx->r24);
    // lw          $v0, 0x300($gp)
    ctx->r2 = MEM_W(0X300, ctx->r28);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // addu        $v0, $t4, $v0
    ctx->r2 = ADD32(ctx->r12, ctx->r2);
    // sw          $v0, 0x300($gp)
    MEM_W(0X300, ctx->r28) = ctx->r2;
    // lh          $v0, 0x2FC($gp)
    ctx->r2 = MEM_HS(0X2FC, ctx->r28);
    // andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_800271B0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800271B0;
    }
    // nop

    // lh          $v0, 0x2FA($gp)
    ctx->r2 = MEM_HS(0X2FA, ctx->r28);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_80027318
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80027318;
    }
    // nop

L_8002707C:
    // j           L_800271E0
    // addu        $v0, $a1, $t4
    ctx->r2 = ADD32(ctx->r5, ctx->r12);
    goto L_800271E0;
    // addu        $v0, $a1, $t4
    ctx->r2 = ADD32(ctx->r5, ctx->r12);
L_80027084:
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // div         $zero, $a0, $t0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r8)));
    // bne         $t0, $zero, L_80027098
    if (ctx->r8 != 0) {
        // nop
    
        goto L_80027098;
    }
    // nop

    // break       7
    do_break(2147643540);
L_80027098:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $t0, $at, L_800270B0
    if (ctx->r8 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_800270B0;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_800270B0
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_800270B0;
    }
    // nop

    // break       6
    do_break(2147643564);
L_800270B0:
    // mflo        $a0
    ctx->r4 = lo;
    // mfhi        $v0
    ctx->r2 = hi;
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // nop

    // mult        $t3, $v0
    result = S64(S32(ctx->r11)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // nop

    // mult        $t5, $a0
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x304($t2)
    ctx->r3 = MEM_W(0X304, ctx->r10);
    // nop

    // lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(0X8, ctx->r3);
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addiu       $t0, $s0, 0x28
    ctx->r8 = ADD32(ctx->r16, 0X28);
    // sltu        $v0, $v0, $t0
    ctx->r2 = ctx->r2 < ctx->r8 ? 1 : 0;
    // mflo        $a0
    ctx->r4 = lo;
    // bne         $v0, $zero, L_80027318
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80027318;
    }
    // nop

    // sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // lw          $v0, 0x328($t2)
    ctx->r2 = MEM_W(0X328, ctx->r10);
    // addu        $v1, $t3, $t1
    ctx->r3 = ADD32(ctx->r11, ctx->r9);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x328($t2)
    MEM_W(0X328, ctx->r10) = ctx->r2;
    // addu        $v0, $t5, $a0
    ctx->r2 = ADD32(ctx->r13, ctx->r4);
    // sb          $t1, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r9;
    // sb          $a0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r4;
    // sb          $v1, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r3;
    // sb          $a0, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r4;
    // sb          $t1, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r9;
    // sb          $v0, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r2;
    // sb          $v1, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r3;
    // sb          $v0, 0x25($s0)
    MEM_B(0X25, ctx->r16) = ctx->r2;
    // lw          $v0, 0x304($gp)
    ctx->r2 = MEM_W(0X304, ctx->r28);
    // nop

    // beq         $v0, $zero, L_800271DC
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_800271DC;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lhu         $v1, -0x7E54($v1)
    ctx->r3 = MEM_HU(-0X7E54, ctx->r3);
    // nop

    // bne         $v1, $v0, L_80027174
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $t4, 0x1
        ctx->r2 = ADD32(ctx->r12, 0X1);
        goto L_80027174;
    }
    // addiu       $v0, $t4, 0x1
    ctx->r2 = ADD32(ctx->r12, 0X1);
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lhu         $v1, -0x7E60($v1)
    ctx->r3 = MEM_HU(-0X7E60, ctx->r3);
    // j           L_80027184
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    goto L_80027184;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
L_80027174:
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lhu         $v1, -0x7E5E($v1)
    ctx->r3 = MEM_HU(-0X7E5E, ctx->r3);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
L_80027184:
    // mflo        $t8
    ctx->r24 = lo;
    // subu        $a1, $a1, $t8
    ctx->r5 = SUB32(ctx->r5, ctx->r24);
    // lw          $v0, 0x300($gp)
    ctx->r2 = MEM_W(0X300, ctx->r28);
    // nop

    // addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // sw          $v0, 0x300($gp)
    MEM_W(0X300, ctx->r28) = ctx->r2;
    // lh          $v0, 0x2FC($gp)
    ctx->r2 = MEM_HS(0X2FC, ctx->r28);
    // andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_800271C8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800271C8;
    }
    // nop

L_800271B0:
    // lw          $v0, 0x308($gp)
    ctx->r2 = MEM_W(0X308, ctx->r28);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x308($gp)
    MEM_W(0X308, ctx->r28) = ctx->r2;
    // j           L_80027318
    // nop

    goto L_80027318;
    // nop

L_800271C8:
    // lh          $v0, 0x2FA($gp)
    ctx->r2 = MEM_HS(0X2FA, ctx->r28);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_80027318
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80027318;
    }
    // nop

L_800271DC:
    // addu        $v0, $a1, $t7
    ctx->r2 = ADD32(ctx->r5, ctx->r15);
L_800271E0:
    // sh          $v0, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r2;
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // sh          $a1, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r5;
    // sh          $a1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r5;
    // sh          $a2, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r6;
    // sh          $a2, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r6;
    // sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
    // sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
    // lwl         $v0, 0x3($a3)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r7);
    // lwr         $v0, 0x0($a3)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r7);
    // nop

    // swl         $v0, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r2);
    // swr         $v0, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r2);
    // lbu         $v0, 0x10($sp)
    ctx->r2 = MEM_BU(0X10, ctx->r29);
    // lbu         $v1, 0x12($sp)
    ctx->r3 = MEM_BU(0X12, ctx->r29);
    // addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x11($sp)
    ctx->r2 = MEM_BU(0X11, ctx->r29);
    // addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // sb          $v1, 0x12($sp)
    MEM_B(0X12, ctx->r29) = ctx->r3;
    // addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // sb          $v0, 0x11($sp)
    MEM_B(0X11, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x10($sp)
    ctx->r2 = MEM_BU(0X10, ctx->r29);
    // nop

    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x11($sp)
    ctx->r2 = MEM_BU(0X11, ctx->r29);
    // nop

    // sb          $v0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x12($sp)
    ctx->r2 = MEM_BU(0X12, ctx->r29);
    // nop

    // sb          $v0, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r2;
    // lbu         $a1, 0x3($a3)
    ctx->r5 = MEM_BU(0X3, ctx->r7);
    // nop

    // andi        $v0, $a1, 0x80
    ctx->r2 = ctx->r5 & 0X80;
    // beq         $v0, $zero, L_80027290
    if (ctx->r2 == 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80027290;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // andi        $a1, $a1, 0x3
    ctx->r5 = ctx->r5 & 0X3;
    // addiu       $a2, $zero, 0x380
    ctx->r6 = ADD32(0, 0X380);
    // jal         0x8007C704
    // addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    GetTPage(rdram, ctx);
    goto after_0;
    // addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_0:
    // addiu       $a0, $zero, 0x230
    ctx->r4 = ADD32(0, 0X230);
    // j           L_800272A8
    // addiu       $a1, $zero, 0x1F1
    ctx->r5 = ADD32(0, 0X1F1);
    goto L_800272A8;
    // addiu       $a1, $zero, 0x1F1
    ctx->r5 = ADD32(0, 0X1F1);
L_80027290:
    // andi        $a1, $a1, 0x3
    ctx->r5 = ctx->r5 & 0X3;
    // addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // jal         0x8007C704
    // addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    GetTPage(rdram, ctx);
    goto after_1;
    // addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_1:
    // addiu       $a0, $zero, 0x230
    ctx->r4 = ADD32(0, 0X230);
    // addiu       $a1, $zero, 0x1EF
    ctx->r5 = ADD32(0, 0X1EF);
L_800272A8:
    // jal         0x8007C744
    // sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    GetClut(rdram, ctx);
    goto after_2;
    // sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    after_2:
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
    // lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // addiu       $a0, $a0, -0x2F70
    ctx->r4 = ADD32(ctx->r4, -0X2F70);
    // sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lui         $a2, 0xFF00
    ctx->r6 = S32(0XFF00 << 16);
    // lw          $v0, 0xE4($a0)
    ctx->r2 = MEM_W(0XE4, ctx->r4);
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // and         $v1, $v1, $a2
    ctx->r3 = ctx->r3 & ctx->r6;
    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // lw          $v1, 0xE4($a0)
    ctx->r3 = MEM_W(0XE4, ctx->r4);
    // nop

    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // and         $a1, $s0, $a1
    ctx->r5 = ctx->r16 & ctx->r5;
    // and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80027318:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
