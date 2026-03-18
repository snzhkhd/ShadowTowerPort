#include "recomp.h"
#include "disable_warnings.h"

void sub_8003CB88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $t5, $v0, -0x70A0
    ctx->r13 = ADD32(ctx->r2, -0X70A0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // addu        $t4, $a1, $zero
    ctx->r12 = ADD32(ctx->r5, 0);
    // addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // addu        $t2, $a1, $zero
    ctx->r10 = ADD32(ctx->r5, 0);
    // addu        $t3, $a1, $zero
    ctx->r11 = ADD32(ctx->r5, 0);
    // addu        $t6, $a1, $zero
    ctx->r14 = ADD32(ctx->r5, 0);
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $t8, $v0, 0x7810
    ctx->r24 = ADD32(ctx->r2, 0X7810);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $t7, $v0, 0x1CFC
    ctx->r15 = ADD32(ctx->r2, 0X1CFC);
L_8003CBC8:
    // addiu       $v0, $a3, -0x4
    ctx->r2 = ADD32(ctx->r7, -0X4);
    // sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_8003CDB0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
        goto L_8003CDB0;
    }
    // addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // beq         $a3, $v0, L_8003CDB0
    if (ctx->r7 == ctx->r2) {
        // addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
        goto L_8003CDB0;
    }
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // beq         $a3, $v0, L_8003CDB0
    if (ctx->r7 == ctx->r2) {
        // addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
        goto L_8003CDB0;
    }
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // beq         $a3, $v0, L_8003CDB0
    if (ctx->r7 == ctx->r2) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_8003CDB0;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // lhu         $v1, 0x0($t5)
    ctx->r3 = MEM_HU(0X0, ctx->r13);
    // nop

    // beq         $v1, $v0, L_8003CDB0
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8003CDB0;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(0X20, ctx->r3);
    // nop

    // andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(0X20, ctx->r3);
    // nop

    // srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x22($v1)
    ctx->r2 = MEM_BU(0X22, ctx->r3);
    // nop

    // sw          $v0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x20($v1)
    ctx->r2 = MEM_BU(0X20, ctx->r3);
    // nop

    // srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(0X20, ctx->r3);
    // nop

    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    // andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x23($v1)
    ctx->r2 = MEM_BU(0X23, ctx->r3);
    // addu        $a0, $sp, $zero
    ctx->r4 = ADD32(ctx->r29, 0);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_8003CC78:
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // nop

    // addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // sltiu       $v0, $v1, 0x8
    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
    // beq         $v0, $zero, L_8003CD9C
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_8003CD9C;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $t7
    gpr jr_addend_8003CC9C;
    jr_addend_8003CC9C = ctx->r2;
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // lw          $v0, 0x0($v0)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8003CC9C >> 2) {
        case 0: goto L_8003CCA4; break;
        case 1: goto L_8003CCC4; break;
        case 2: goto L_8003CCE4; break;
        case 3: goto L_8003CD04; break;
        case 4: goto L_8003CD38; break;
        case 5: goto L_8003CD58; break;
        case 6: goto L_8003CD78; break;
        case 7: goto L_8003CD98; break;
        default: switch_error(__func__, 0x8003CC9C, 0x80011CFC);
    }
    // nop

L_8003CCA4:
    // lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(0X10, ctx->r4);
    // nop

    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // slti        $v0, $a1, 0x65
    ctx->r2 = SIGNED(ctx->r5) < 0X65 ? 1 : 0;
    // bne         $v0, $zero, L_8003CD9C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003CD9C;
    }
    // nop

    // j           L_8003CD9C
    // addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    goto L_8003CD9C;
    // addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
L_8003CCC4:
    // lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(0X10, ctx->r4);
    // nop

    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // slti        $v0, $a2, 0x65
    ctx->r2 = SIGNED(ctx->r6) < 0X65 ? 1 : 0;
    // bne         $v0, $zero, L_8003CD9C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003CD9C;
    }
    // nop

    // j           L_8003CD9C
    // addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    goto L_8003CD9C;
    // addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
L_8003CCE4:
    // lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(0X10, ctx->r4);
    // nop

    // addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // slti        $v0, $t0, 0x15
    ctx->r2 = SIGNED(ctx->r8) < 0X15 ? 1 : 0;
    // bne         $v0, $zero, L_8003CD9C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003CD9C;
    }
    // nop

    // j           L_8003CD9C
    // addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    goto L_8003CD9C;
    // addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
L_8003CD04:
    // bltz        $t4, L_8003CD9C
    if (SIGNED(ctx->r12) < 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8003CD9C;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(0X10, ctx->r4);
    // nop

    // bne         $v1, $v0, L_8003CD24
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8003CD24;
    }
    // nop

    // j           L_8003CD9C
    // addu        $t4, $v0, $zero
    ctx->r12 = ADD32(ctx->r2, 0);
    goto L_8003CD9C;
    // addu        $t4, $v0, $zero
    ctx->r12 = ADD32(ctx->r2, 0);
L_8003CD24:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_8003CD9C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8003CD9C;
    }
    // nop

    // j           L_8003CD9C
    // addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    goto L_8003CD9C;
    // addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_8003CD38:
    // lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(0X10, ctx->r4);
    // nop

    // addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // slti        $v0, $t1, 0x65
    ctx->r2 = SIGNED(ctx->r9) < 0X65 ? 1 : 0;
    // bne         $v0, $zero, L_8003CD9C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003CD9C;
    }
    // nop

    // j           L_8003CD9C
    // addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    goto L_8003CD9C;
    // addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
L_8003CD58:
    // lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(0X10, ctx->r4);
    // nop

    // addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // slti        $v0, $t2, 0x65
    ctx->r2 = SIGNED(ctx->r10) < 0X65 ? 1 : 0;
    // bne         $v0, $zero, L_8003CD9C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003CD9C;
    }
    // nop

    // j           L_8003CD9C
    // addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    goto L_8003CD9C;
    // addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
L_8003CD78:
    // lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(0X10, ctx->r4);
    // nop

    // addu        $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    // slti        $v0, $t3, 0x65
    ctx->r2 = SIGNED(ctx->r11) < 0X65 ? 1 : 0;
    // bne         $v0, $zero, L_8003CD9C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003CD9C;
    }
    // nop

    // j           L_8003CD9C
    // addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    goto L_8003CD9C;
    // addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
L_8003CD98:
    // addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_8003CD9C:
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // addiu       $v0, $sp, 0xC
    ctx->r2 = ADD32(ctx->r29, 0XC);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8003CC78
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003CC78;
    }
    // nop

L_8003CDB0:
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // slti        $v0, $a3, 0x11
    ctx->r2 = SIGNED(ctx->r7) < 0X11 ? 1 : 0;
    // bne         $v0, $zero, L_8003CBC8
    if (ctx->r2 != 0) {
        // addiu       $t5, $t5, 0x2
        ctx->r13 = ADD32(ctx->r13, 0X2);
        goto L_8003CBC8;
    }
    // addiu       $t5, $t5, 0x2
    ctx->r13 = ADD32(ctx->r13, 0X2);
    // beq         $a1, $zero, L_8003CE00
    if (ctx->r5 == 0) {
        // addiu       $v0, $zero, 0x64
        ctx->r2 = ADD32(0, 0X64);
        goto L_8003CE00;
    }
    // addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // div         $zero, $v0, $a1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r5)));
    // bne         $a1, $zero, L_8003CDD8
    if (ctx->r5 != 0) {
        // nop
    
        goto L_8003CDD8;
    }
    // nop

    // break       7
    do_break(2147732948);
L_8003CDD8:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a1, $at, L_8003CDF0
    if (ctx->r5 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003CDF0;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8003CDF0
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8003CDF0;
    }
    // nop

    // break       6
    do_break(2147732972);
L_8003CDF0:
    // mflo        $v0
    ctx->r2 = lo;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // j           L_8003CE08
    // sb          $v0, -0x6F14($v1)
    MEM_B(-0X6F14, ctx->r3) = ctx->r2;
    goto L_8003CE08;
    // sb          $v0, -0x6F14($v1)
    MEM_B(-0X6F14, ctx->r3) = ctx->r2;
L_8003CE00:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sb          $zero, -0x6F14($v0)
    MEM_B(-0X6F14, ctx->r2) = 0;
L_8003CE08:
    // beq         $a2, $zero, L_8003CE48
    if (ctx->r6 == 0) {
        // addiu       $v0, $zero, 0x64
        ctx->r2 = ADD32(0, 0X64);
        goto L_8003CE48;
    }
    // addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // bne         $a2, $zero, L_8003CE20
    if (ctx->r6 != 0) {
        // nop
    
        goto L_8003CE20;
    }
    // nop

    // break       7
    do_break(2147733020);
L_8003CE20:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a2, $at, L_8003CE38
    if (ctx->r6 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003CE38;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8003CE38
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8003CE38;
    }
    // nop

    // break       6
    do_break(2147733044);
L_8003CE38:
    // mflo        $v0
    ctx->r2 = lo;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // j           L_8003CE50
    // sb          $v0, -0x6F13($v1)
    MEM_B(-0X6F13, ctx->r3) = ctx->r2;
    goto L_8003CE50;
    // sb          $v0, -0x6F13($v1)
    MEM_B(-0X6F13, ctx->r3) = ctx->r2;
L_8003CE48:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sb          $zero, -0x6F13($v0)
    MEM_B(-0X6F13, ctx->r2) = 0;
L_8003CE50:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8) << 2;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // bgez        $t4, L_8003CE74
    if (SIGNED(ctx->r12) >= 0) {
        // sb          $v0, 0x1C6($v1)
        MEM_B(0X1C6, ctx->r3) = ctx->r2;
        goto L_8003CE74;
    }
    // sb          $v0, 0x1C6($v1)
    MEM_B(0X1C6, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // j           L_8003CE88
    // sb          $v0, 0x1C7($v1)
    MEM_B(0X1C7, ctx->r3) = ctx->r2;
    goto L_8003CE88;
    // sb          $v0, 0x1C7($v1)
    MEM_B(0X1C7, ctx->r3) = ctx->r2;
L_8003CE74:
    // blez        $t4, L_8003CE84
    if (SIGNED(ctx->r12) <= 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8003CE84;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // j           L_8003CE88
    // sb          $v0, 0x1C7($v1)
    MEM_B(0X1C7, ctx->r3) = ctx->r2;
    goto L_8003CE88;
    // sb          $v0, 0x1C7($v1)
    MEM_B(0X1C7, ctx->r3) = ctx->r2;
L_8003CE84:
    // sb          $zero, 0x1C7($v1)
    MEM_B(0X1C7, ctx->r3) = 0;
L_8003CE88:
    // lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // sll         $v0, $t1, 2
    ctx->r2 = S32(ctx->r9) << 2;
    // addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // sb          $t2, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r10;
    // sb          $t3, 0x1CA($a0)
    MEM_B(0X1CA, ctx->r4) = ctx->r11;
    // sb          $t6, 0x1CB($a0)
    MEM_B(0X1CB, ctx->r4) = ctx->r14;
    // mfhi        $t9
    ctx->r25 = hi;
    // sra         $v1, $t9, 5
    ctx->r3 = S32(ctx->r25) >> 5;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sb          $v0, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r2;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
