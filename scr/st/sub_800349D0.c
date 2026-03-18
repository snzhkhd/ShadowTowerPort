#include "recomp.h"
#include "disable_warnings.h"

void sub_800349D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // sw          $s6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r22;
    // addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r17;
    // addiu       $s1, $a0, 0x4
    ctx->r17 = ADD32(ctx->r4, 0X4);
    // sw          $ra, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r31;
    // sw          $fp, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r30;
    // sw          $s7, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r23;
    // sw          $s5, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r20;
    // sw          $s3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r19;
    // sw          $s2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r18;
    // sw          $s0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r16;
    // sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // sw          $a2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r6;
    // sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // lw          $fp, 0xC0($sp)
    ctx->r30 = MEM_W(0XC0, ctx->r29);
    // andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // srl         $v1, $v0, 16
    ctx->r3 = S32(U32(ctx->r2) >> 16);
    // andi        $s7, $v1, 0xF
    ctx->r23 = ctx->r3 & 0XF;
    // srl         $v1, $v0, 20
    ctx->r3 = S32(U32(ctx->r2) >> 20);
    // andi        $s4, $v1, 0xF
    ctx->r20 = ctx->r3 & 0XF;
    // srl         $v0, $v0, 24
    ctx->r2 = S32(U32(ctx->r2) >> 24);
    // jal         0x800347AC
    // sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    sub_800347AC(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    after_0:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // bne         $s2, $zero, L_80034A58
    if (ctx->r18 != 0) {
        // addiu       $s5, $sp, 0x38
        ctx->r21 = ADD32(ctx->r29, 0X38);
        goto L_80034A58;
    }
    // addiu       $s5, $sp, 0x38
    ctx->r21 = ADD32(ctx->r29, 0X38);
    // addiu       $s2, $sp, 0x28
    ctx->r18 = ADD32(ctx->r29, 0X28);
    // j           L_80034A6C
    // addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    goto L_80034A6C;
    // addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
L_80034A58:
    // lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(0X4, ctx->r18);
    // nop

    // lw          $s0, 0x44($v0)
    ctx->r16 = MEM_W(0X44, ctx->r2);
    // addiu       $s5, $v0, 0x4
    ctx->r21 = ADD32(ctx->r2, 0X4);
    // sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
L_80034A6C:
    // sltiu       $v0, $s7, 0x9
    ctx->r2 = ctx->r23 < 0X9 ? 1 : 0;
    // beq         $v0, $zero, L_80034E1C
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8001
        ctx->r2 = S32(0X8001 << 16);
        goto L_80034E1C;
    }
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x14A8
    ctx->r2 = ADD32(ctx->r2, 0X14A8);
    // sll         $v1, $s7, 2
    ctx->r3 = S32(ctx->r23) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_80034A8C;
    jr_addend_80034A8C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80034A8C >> 2) {
        case 0: goto L_80034A94; break;
        case 1: goto L_80034AB0; break;
        case 2: goto L_80034D5C; break;
        case 3: goto L_80034D94; break;
        case 4: goto L_80034E1C; break;
        case 5: goto L_80034E1C; break;
        case 6: goto L_80034E1C; break;
        case 7: goto L_80034E1C; break;
        case 8: goto L_80034DD0; break;
        default: switch_error(__func__, 0x80034A8C, 0x800114A8);
    }
    // nop

L_80034A94:
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(0X0, ctx->r17);
    // lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(0X4, ctx->r17);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // j           L_80034E1C
    // sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    goto L_80034E1C;
    // sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
L_80034AB0:
    // andi        $v0, $s4, 0x1
    ctx->r2 = ctx->r20 & 0X1;
    // beq         $v0, $zero, L_80034C4C
    if (ctx->r2 == 0) {
        // andi        $v0, $s4, 0x2
        ctx->r2 = ctx->r20 & 0X2;
        goto L_80034C4C;
    }
    // andi        $v0, $s4, 0x2
    ctx->r2 = ctx->r20 & 0X2;
    // beq         $v0, $zero, L_80034B4C
    if (ctx->r2 == 0) {
        // lui         $a1, 0xB60B
        ctx->r5 = S32(0XB60B << 16);
        goto L_80034B4C;
    }
    // lui         $a1, 0xB60B
    ctx->r5 = S32(0XB60B << 16);
    // lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(0X0, ctx->r17);
    // ori         $a1, $a1, 0x60B7
    ctx->r5 = ctx->r5 | 0X60B7;
    // mult        $a0, $a1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x10($s0)
    ctx->r2 = MEM_HU(0X10, ctx->r16);
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v1, $t0, $a0
    ctx->r3 = ADD32(ctx->r8, ctx->r4);
    // sra         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) >> 8;
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(0X4, ctx->r17);
    // nop

    // mult        $a0, $a1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x12($s0)
    ctx->r2 = MEM_HU(0X12, ctx->r16);
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v1, $t0, $a0
    ctx->r3 = ADD32(ctx->r8, ctx->r4);
    // sra         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) >> 8;
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
    // lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(0X8, ctx->r17);
    // nop

    // mult        $a0, $a1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // lhu         $v0, 0x14($s0)
    ctx->r2 = MEM_HU(0X14, ctx->r16);
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v1, $t0, $a0
    ctx->r3 = ADD32(ctx->r8, ctx->r4);
    // sra         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) >> 8;
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
L_80034B4C:
    // andi        $v0, $s4, 0x4
    ctx->r2 = ctx->r20 & 0X4;
    // beq         $v0, $zero, L_80034BD8
    if (ctx->r2 == 0) {
        // andi        $v0, $s4, 0x8
        ctx->r2 = ctx->r20 & 0X8;
        goto L_80034BD8;
    }
    // andi        $v0, $s4, 0x8
    ctx->r2 = ctx->r20 & 0X8;
    // lh          $v1, 0x0($s1)
    ctx->r3 = MEM_HS(0X0, ctx->r17);
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_80034B78
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80034B78;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80034B78:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // lh          $v1, 0x2($s1)
    ctx->r3 = MEM_HS(0X2, ctx->r17);
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_80034BA0
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80034BA0;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80034BA0:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // lh          $v1, 0x4($s1)
    ctx->r3 = MEM_HS(0X4, ctx->r17);
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_80034BC8
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80034BC8;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80034BC8:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // andi        $v0, $s4, 0x8
    ctx->r2 = ctx->r20 & 0X8;
L_80034BD8:
    // beq         $v0, $zero, L_80034C1C
    if (ctx->r2 == 0) {
        // addiu       $a0, $s0, 0x10
        ctx->r4 = ADD32(ctx->r16, 0X10);
        goto L_80034C1C;
    }
    // addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(0X18, ctx->r16);
    // lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(0X0, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(0X1C, ctx->r16);
    // lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(0X4, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(0X20, ctx->r16);
    // lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(0X8, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
L_80034C1C:
    // jal         0x80074EC4
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    RotMatrix(rdram, ctx);
    goto after_1;
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_1:
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // jal         0x80074D84
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    ScaleMatrix(rdram, ctx);
    goto after_2;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // jal         0x80074D54
    // addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    TransMatrix(rdram, ctx);
    goto after_3;
    // addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_3:
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // j           L_80034E1C
    // sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    goto L_80034E1C;
    // sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
L_80034C4C:
    // andi        $s2, $s4, 0x2
    ctx->r18 = ctx->r20 & 0X2;
    // beq         $s2, $zero, L_80034CD4
    if (ctx->r18 == 0) {
        // lui         $a0, 0xB60B
        ctx->r4 = S32(0XB60B << 16);
        goto L_80034CD4;
    }
    // lui         $a0, 0xB60B
    ctx->r4 = S32(0XB60B << 16);
    // lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(0X0, ctx->r17);
    // ori         $a0, $a0, 0x60B7
    ctx->r4 = ctx->r4 | 0X60B7;
    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(0X4, ctx->r17);
    // nop

    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
    // lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(0X8, ctx->r17);
    // nop

    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // jal         0x80074EC4
    // sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
    RotMatrix(rdram, ctx);
    goto after_4;
    // sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
    after_4:
L_80034CD4:
    // andi        $v0, $s4, 0x4
    ctx->r2 = ctx->r20 & 0X4;
    // beq         $v0, $zero, L_80034D24
    if (ctx->r2 == 0) {
        // andi        $v0, $s4, 0x8
        ctx->r2 = ctx->r20 & 0X8;
        goto L_80034D24;
    }
    // andi        $v0, $s4, 0x8
    ctx->r2 = ctx->r20 & 0X8;
    // lh          $v0, 0x0($s1)
    ctx->r2 = MEM_HS(0X0, ctx->r17);
    // nop

    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // lh          $v0, 0x2($s1)
    ctx->r2 = MEM_HS(0X2, ctx->r17);
    // nop

    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // lh          $v0, 0x4($s1)
    ctx->r2 = MEM_HS(0X4, ctx->r17);
    // addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // bne         $s2, $zero, L_80034D14
    if (ctx->r18 != 0) {
        // sw          $v0, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r2;
        goto L_80034D14;
    }
    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // jal         0x80074EC4
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    RotMatrix(rdram, ctx);
    goto after_5;
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_5:
L_80034D14:
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // jal         0x80074D84
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    ScaleMatrix(rdram, ctx);
    goto after_6;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_6:
    // andi        $v0, $s4, 0x8
    ctx->r2 = ctx->r20 & 0X8;
L_80034D24:
    // beq         $v0, $zero, L_80034E1C
    if (ctx->r2 == 0) {
        // addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
        goto L_80034E1C;
    }
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // nop

    // sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // nop

    // sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(0X8, ctx->r17);
    // addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // jal         0x80074D54
    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    TransMatrix(rdram, ctx);
    goto after_7;
    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    after_7:
    // j           L_80034E1C
    // nop

    goto L_80034E1C;
    // nop

L_80034D5C:
    // beq         $fp, $zero, L_80034E1C
    if (ctx->r30 == 0) {
        // nop
    
        goto L_80034E1C;
    }
    // nop

    // lhu         $a2, 0x0($s1)
    ctx->r6 = MEM_HU(0X0, ctx->r17);
    // lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(0XB8, ctx->r29);
    // jal         0x8003498C
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    sub_8003498C(rdram, ctx);
    goto after_8;
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    after_8:
    // sh          $v0, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(0X8, ctx->r18);
    // lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(0XBC, ctx->r29);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // j           L_80034E1C
    // sb          $v0, 0xA($s2)
    MEM_B(0XA, ctx->r18) = ctx->r2;
    goto L_80034E1C;
    // sb          $v0, 0xA($s2)
    MEM_B(0XA, ctx->r18) = ctx->r2;
L_80034D94:
    // lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(0X0, ctx->r17);
    // nop

    // beq         $a1, $zero, L_80034DAC
    if (ctx->r5 == 0) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_80034DAC;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // bne         $a1, $v0, L_80034DB8
    if (ctx->r5 != ctx->r2) {
        // nop
    
        goto L_80034DB8;
    }
    // nop

L_80034DAC:
    // lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(0X4, ctx->r18);
    // j           L_80034E1C
    // sw          $zero, 0x48($v0)
    MEM_W(0X48, ctx->r2) = 0;
    goto L_80034E1C;
    // sw          $zero, 0x48($v0)
    MEM_W(0X48, ctx->r2) = 0;
L_80034DB8:
    // jal         0x800347AC
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    sub_800347AC(rdram, ctx);
    goto after_9;
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_9:
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // j           L_80034E1C
    // sw          $v0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r2;
    goto L_80034E1C;
    // sw          $v0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r2;
L_80034DD0:
    // beq         $s6, $zero, L_80034E1C
    if (ctx->r22 == 0) {
        // nop
    
        goto L_80034E1C;
    }
    // nop

    // beq         $s4, $zero, L_80034DF0
    if (ctx->r20 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80034DF0;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $s4, $v0, L_80034E14
    if (ctx->r20 == ctx->r2) {
        // addu        $a0, $s6, $zero
        ctx->r4 = ADD32(ctx->r22, 0);
        goto L_80034E14;
    }
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // j           L_80034E1C
    // nop

    goto L_80034E1C;
    // nop

L_80034DF0:
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // jal         0x800347AC
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    sub_800347AC(rdram, ctx);
    goto after_10;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_10:
    // bne         $v0, $zero, L_80034E1C
    if (ctx->r2 != 0) {
        // addu        $a0, $s6, $zero
        ctx->r4 = ADD32(ctx->r22, 0);
        goto L_80034E1C;
    }
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // jal         0x800347F8
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    sub_800347F8(rdram, ctx);
    goto after_11;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_11:
    // j           L_80034E1C
    // nop

    goto L_80034E1C;
    // nop

L_80034E14:
    // jal         0x80034928
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    sub_80034928(rdram, ctx);
    goto after_12;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_12:
L_80034E1C:
    // lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(0X80, ctx->r29);
    // nop

    // sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8) << 2;
    // lw          $t0, 0xB0($sp)
    ctx->r8 = MEM_W(0XB0, ctx->r29);
    // nop

    // addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // lw          $ra, 0xAC($sp)
    ctx->r31 = MEM_W(0XAC, ctx->r29);
    // lw          $fp, 0xA8($sp)
    ctx->r30 = MEM_W(0XA8, ctx->r29);
    // lw          $s7, 0xA4($sp)
    ctx->r23 = MEM_W(0XA4, ctx->r29);
    // lw          $s6, 0xA0($sp)
    ctx->r22 = MEM_W(0XA0, ctx->r29);
    // lw          $s5, 0x9C($sp)
    ctx->r21 = MEM_W(0X9C, ctx->r29);
    // lw          $s4, 0x98($sp)
    ctx->r20 = MEM_W(0X98, ctx->r29);
    // lw          $s3, 0x94($sp)
    ctx->r19 = MEM_W(0X94, ctx->r29);
    // lw          $s2, 0x90($sp)
    ctx->r18 = MEM_W(0X90, ctx->r29);
    // lw          $s1, 0x8C($sp)
    ctx->r17 = MEM_W(0X8C, ctx->r29);
    // lw          $s0, 0x88($sp)
    ctx->r16 = MEM_W(0X88, ctx->r29);
    // addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // jr          $ra
    // nop

    return;
    // nop

;}
