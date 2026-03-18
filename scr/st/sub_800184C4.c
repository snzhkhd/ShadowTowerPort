#include "recomp.h"
#include "disable_warnings.h"

void sub_800184C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // addu        $fp, $a2, $zero
    ctx->r30 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lw          $v1, 0x8C($s0)
    ctx->r3 = MEM_W(0X8C, ctx->r16);
    // lbu         $a0, 0x6DFC($v0)
    ctx->r4 = MEM_BU(0X6DFC, ctx->r2);
    // lw          $s7, 0x10($s0)
    ctx->r23 = MEM_W(0X10, ctx->r16);
    // addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // andi        $v0, $a0, 0x2
    ctx->r2 = ctx->r4 & 0X2;
    // beq         $v0, $zero, L_8001853C
    if (ctx->r2 == 0) {
        // sw          $v1, 0x8C($s0)
        MEM_W(0X8C, ctx->r16) = ctx->r3;
        goto L_8001853C;
    }
    // sw          $v1, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r3;
    // lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // j           L_8001854C
    // addiu       $s4, $v0, -0x7BC0
    ctx->r20 = ADD32(ctx->r2, -0X7BC0);
    goto L_8001854C;
    // addiu       $s4, $v0, -0x7BC0
    ctx->r20 = ADD32(ctx->r2, -0X7BC0);
L_8001853C:
    // andi        $v0, $a0, 0x4
    ctx->r2 = ctx->r4 & 0X4;
    // beq         $v0, $zero, L_8001854C
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8002
        ctx->r2 = S32(0X8002 << 16);
        goto L_8001854C;
    }
    // lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // addiu       $s4, $v0, -0x7B80
    ctx->r20 = ADD32(ctx->r2, -0X7B80);
L_8001854C:
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // beq         $v0, $zero, L_80018744
    if (ctx->r2 == 0) {
        // addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_80018744;
    }
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // andi        $v0, $a3, 0x2
    ctx->r2 = ctx->r7 & 0X2;
    // ori         $s6, $v0, 0x24
    ctx->r22 = ctx->r2 | 0X24;
    // lui         $s2, 0x5555
    ctx->r18 = S32(0X5555 << 16);
    // ori         $s2, $s2, 0x5556
    ctx->r18 = ctx->r18 | 0X5556;
    // lui         $v0, 0x60
    ctx->r2 = S32(0X60 << 16);
    // and         $s5, $a3, $v0
    ctx->r21 = ctx->r7 & ctx->r2;
L_80018570:
    // lhu         $v1, 0xE($a1)
    ctx->r3 = MEM_HU(0XE, ctx->r5);
    // lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(0X40, ctx->r16);
    // lhu         $a0, 0x12($a1)
    ctx->r4 = MEM_HU(0X12, ctx->r5);
    // addu        $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // addu        $t1, $v0, $a0
    ctx->r9 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v1, 0x10($a1)
    ctx->r3 = MEM_HU(0X10, ctx->r5);
    // lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(0X0, ctx->r10);
    // lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(0X0, ctx->r9);
    // addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(0X0, ctx->r8);
    // mtc2        $t3, $12
    gte_mtc2(ctx, 11, 12);
    // mtc2        $t5, $14
    gte_mtc2(ctx, 13, 14);
    // mtc2        $t4, $13
    gte_mtc2(ctx, 12, 13);
    // addiu       $s3, $a1, 0x14
    ctx->r19 = ADD32(ctx->r5, 0X14);
    // nop

    // nop

    // .word       0x4B400006                   # INVALID     $k0, $zero, 0x6 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B400006);
    // lbu         $v0, 0xB($a1)
    ctx->r2 = MEM_BU(0XB, ctx->r5);
    // nop

    // or          $v0, $v0, $s6
    ctx->r2 = ctx->r2 | ctx->r22;
    // sb          $v0, 0x63($s0)
    MEM_B(0X63, ctx->r16) = ctx->r2;
    // addiu       $v0, $s0, 0x70
    ctx->r2 = ADD32(ctx->r16, 0X70);
    // swc2        $24, 0x0($v0)
    gte_swc2(rdram, ctx, 24, 2, 0);
    // lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(0X70, ctx->r16);
    // nop

    // blez        $v0, L_80018734
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_80018734;
    }
    // nop

    // lh          $v1, 0x4($t2)
    ctx->r3 = MEM_HS(0X4, ctx->r10);
    // lh          $v0, 0x4($t0)
    ctx->r2 = MEM_HS(0X4, ctx->r8);
    // lh          $a0, 0x4($t1)
    ctx->r4 = MEM_HS(0X4, ctx->r9);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sra         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) >> 5;
    // mult        $v0, $s2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lbu         $v0, 0xA($a1)
    ctx->r2 = MEM_BU(0XA, ctx->r5);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // mfhi        $t3
    ctx->r11 = hi;
    // subu        $v1, $t3, $v1
    ctx->r3 = SUB32(ctx->r11, ctx->r3);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(0X4, ctx->r16);
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // slt         $v1, $a3, $v1
    ctx->r3 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v1, $zero, L_80018734
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80018734;
    }
    // nop

    // lw          $v0, 0x80($s0)
    ctx->r2 = MEM_W(0X80, ctx->r16);
    // nop

    // slt         $v0, $v0, $a3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // beq         $v0, $zero, L_80018734
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80018734;
    }
    // nop

    // lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(0X10, ctx->r16);
    // nop

    // addiu       $v0, $a2, 0x20
    ctx->r2 = ADD32(ctx->r6, 0X20);
    // sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // swc2        $12, 0x8($a2)
    gte_swc2(rdram, ctx, 12, 6, 8);
    // swc2        $13, 0x10($a2)
    gte_swc2(rdram, ctx, 13, 6, 16);
    // swc2        $14, 0x18($a2)
    gte_swc2(rdram, ctx, 14, 6, 24);
    // lhu         $v1, 0xC($a1)
    ctx->r3 = MEM_HU(0XC, ctx->r5);
    // lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(0X24, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    // addiu       $v0, $s0, 0x60
    ctx->r2 = ADD32(ctx->r16, 0X60);
    // lwc2        $6, 0x0($v0)
    gte_lwc2(rdram, ctx, 6, 2, 0);
    // lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(0X4, ctx->r5);
    // nop

    // or          $v0, $v0, $s5
    ctx->r2 = ctx->r2 | ctx->r21;
    // sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // lh          $v0, 0x6($t2)
    ctx->r2 = MEM_HS(0X6, ctx->r10);
    // lh          $v1, 0x6($t0)
    ctx->r3 = MEM_HS(0X6, ctx->r8);
    // lh          $a0, 0x6($t1)
    ctx->r4 = MEM_HS(0X6, ctx->r9);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // mult        $v0, $s2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t4
    ctx->r12 = hi;
    // subu        $v0, $t4, $v0
    ctx->r2 = SUB32(ctx->r12, ctx->r2);
    // mtc2        $v0, $8
    gte_mtc2(ctx, 2, 8);
    // lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(0X8, ctx->r5);
    // nop

    // sh          $v0, 0x1C($a2)
    MEM_H(0X1C, ctx->r6) = ctx->r2;
    // .word       0x4AE80413                   # INVALID     $s7, $t0, 0x413 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4AE80413);
    // lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // sll         $a0, $a3, 2
    ctx->r4 = S32(ctx->r7) << 2;
    // addu        $a0, $a0, $fp
    ctx->r4 = ADD32(ctx->r4, ctx->r30);
    // ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // lui         $v0, 0x700
    ctx->r2 = S32(0X700 << 16);
    // and         $v1, $v1, $a1
    ctx->r3 = ctx->r3 & ctx->r5;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // and         $a1, $a2, $a1
    ctx->r5 = ctx->r6 & ctx->r5;
    // sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // addiu       $a0, $a2, 0x4
    ctx->r4 = ADD32(ctx->r6, 0X4);
    // swc2        $22, 0x0($a0)
    gte_swc2(rdram, ctx, 22, 4, 0);
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, 0x6DFC($v0)
    ctx->r2 = MEM_BU(0X6DFC, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x6
    ctx->r2 = ctx->r2 & 0X6;
    // beq         $v0, $zero, L_80018738
    if (ctx->r2 == 0) {
        // addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
        goto L_80018738;
    }
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // jalr        $s4
    // nop

    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
    goto after_0;
    // nop

    after_0:
L_80018734:
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
L_80018738:
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // bne         $v0, $zero, L_80018570
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_80018570;
    }
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80018744:
    // lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(0X10, ctx->r16);
    // nop

    // subu        $v0, $v0, $s7
    ctx->r2 = SUB32(ctx->r2, ctx->r23);
    // sra         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) >> 2;
    // bgez        $v1, L_80018760
    if (SIGNED(ctx->r3) >= 0) {
        // sw          $a1, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->r5;
        goto L_80018760;
    }
    // sw          $a1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r5;
    // addiu       $v1, $v1, 0x7
    ctx->r3 = ADD32(ctx->r3, 0X7);
L_80018760:
    // lw          $v0, 0x90($s0)
    ctx->r2 = MEM_W(0X90, ctx->r16);
    // sra         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) >> 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->r2;
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
